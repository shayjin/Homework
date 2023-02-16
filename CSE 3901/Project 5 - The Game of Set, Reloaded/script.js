// represents a card, with 4 features: color, texture, number, and shape
class Card{
    // initializes the card with 4 features
    constructor(color, texture, number, shape) {
        this.color = color;
        this.texture = texture;
        this.number = number;
        this.shape = shape;
    }

    //  returns information (features) of the card in a String format
    toString() {
        return this.color + ", " + this.texture + ", " + this.number + ", " +  this.shape;
    }
}

// recreates the hint button after the hint is displayed AND the user guesses a correct set
function remakeHintButton() {
    var hintButton = document.getElementById("hint");
    hintButton.innerText = "";
    var getHintText = document.createTextNode("Get Hint");
    hintButton.appendChild(getHintText);
}

// runs when a card is clicked
function clicked(pos) {
    // resets the selected cards to nothing after finding a set
    if (selectedCardCount == 0) {
        document.getElementById("card1-chosen").innerText = "";
        document.getElementById("card2-chosen").innerText = "";
        document.getElementById("card3-chosen").innerText = "";
    }

    // increments card count
    selectedCardCount++;

    // card chosen by the user
    var cardChosen = document.getElementById(pos).getAttribute("id"); 

    if (selectedCardCount == 1) {
        // adds the chosen card to the selectedCards array
        selectedCards[0] = cardChosen;

        // HTML GUI update
        document.getElementById("card1-chosen").innerText = displayedCards[cardChosen-1].toString();
        document.getElementById("card1-chosen").style.color = displayedCards[cardChosen-1].color;;
        document.getElementById("status").innerText = "";
        document.getElementById(String(cardChosen)).style.backgroundColor = "green";
    } else if (selectedCardCount == 2) {
        // adds the chosen card to the selectedCards array
        selectedCards[1] =  cardChosen;

        // HTML GUI update
        document.getElementById("card2-chosen").innerText = displayedCards[cardChosen-1].toString();
        document.getElementById("card2-chosen").style.color = displayedCards[cardChosen-1].color;;
        document.getElementById(String(cardChosen)).style.backgroundColor = "green";
    } else if (selectedCardCount == 3) {
        // adds the chosen card to the selectedCards array
        selectedCards[2] = cardChosen;

        // HTML GUI update
        document.getElementById(String(selectedCards[0])).style.backgroundColor = "white";
        document.getElementById(String(selectedCards[1])).style.backgroundColor = "white";
        document.getElementById("card3-chosen").innerText = displayedCards[cardChosen-1].toString();
        document.getElementById("card3-chosen").style.color = displayedCards[cardChosen-1].color;

        // checking if the 3 selected cards in the selectedCards array forms a set
        if (isSet(selectedCards[0], selectedCards[1], selectedCards[2])) {
            // HTML GUI update
            document.getElementById("card1-chosen").innerText = "";
            document.getElementById("card2-chosen").innerText = "";
            document.getElementById("card3-chosen").innerText = "";
            document.getElementById("status").innerText = "That was a set!";
            document.getElementById("status").style.color = "green";

            // deals if more there are cards left in the deck
            if (displayedCards.length/3 < setsLeft && displayedCards.length <= 12){
                deal(selectedCards[0], selectedCards[1], selectedCards[2]);
            } else { /* if there are no cards left in the deck, 
                        it deletes 3 selected cards and 
                        move up the cards according to the new length of displayedCards*/

                // deletes 3 selected cards
                delete displayedCards[selectedCards[0]-1];
                delete displayedCards[selectedCards[1]-1];
                delete displayedCards[selectedCards[2]-1];

                var index = 0;
                var temp =[];

                /*  create a new array, temp, and copy all the cards when it is not undefined.
                    the length of temp will be 3 less than the length of displayedCards. */
                for (var i = 0; i < displayedCards.length; i++) {
                    if (displayedCards[i] != undefined) {
                        temp[index] = displayedCards[i];
                        index++;
                    } 
                }

                displayedCards = temp;

            }

            // HTML GUI update
            remakeHintButton(selectedCards[0], selectedCards[1], selectedCards[2]);
            updateSetCount();
            renderCards();

            // if there are no sets left in displayedCards
            if ((setsLeft == 0) || (!setExists(displayedCards))) {
                // prints a message
                document.getElementById("info").innerHTML = "Congratulations! You won the game!";
                alert("Congratulations! You won the game!");
            }

        } else {
            // if the 3 selected cards do not form a set 
            document.getElementById("status").innerText = "That was not a set!";
            document.getElementById("status").style.color = "red";
        }

        // resets selectedCardCount after 3 cards are selected so user can start over and guess again
        selectedCardCount = 0;
    }

}

// dealing 3 cards (after a set has been found)
function deal(first, second, third) {
    // only deals if there are cards left in the deck
    if (setsLeft != displayedCards.length / 3){
        // HTML GUI update
        document.getElementById(String(first)).innerText = "";
        document.getElementById(String(second)).innerText = "";
        document.getElementById(String(third)).innerText = "";

        // drawing cards from the deck
        var card1 = deck.pop();
        var card2 = deck.pop();;
        var card3 = deck.pop();

        displayedCards[first-1] = card1;
        displayedCards[second-1] = card2;
        displayedCards[third-1] = card3;

        // if there are no sets on the table, even after dealing, it deals 3 MORE cards
        if (!setExists()) {
            dealExtra3();
        }

        // add function to the new cards
        document.getElementById(first).onclick = function() {clicked(first)};
        document.getElementById(second).onclick = function() {clicked(second)};
        document.getElementById(third).onclick = function() {clicked(third)};

    }   
}

// deals extra 3 cards (when there are no sets and there are less than 9 cards displaying)
function dealExtra3() {
    // HTML GUI update. If 3 more cards are dealt in the beginning, it prints the following message.
    if (setsLeft == 27){
        document.getElementById("status").innerText = "3 more cards were added because there were no sets in the previous deck."
    } else { // If 3 more cards are dealt during the game, it must have been after user found a set, so it prints the following message.
        document.getElementById("status").innerText = "That was a set. 3 more cards were added because there were no sets in the previous deck."
    }

    // drawing cards from the deck
    var card1 = deck.pop();
    var card2 = deck.pop();;
    var card3 = deck.pop();

    displayedCards.push(card1);
    displayedCards.push(card2);
    displayedCards.push(card3);

    if (!setExists() && deck.length > 0) {
        dealExtra3();
    }
}

// checks whether the cards at index parameters are a set
function isSet (first,second,third) {
    var card1 = displayedCards[first-1];
    var card2 = displayedCards[second-1];
    var card3 = displayedCards[third-1];
    
    if (card1 != undefined && card2 != undefined && card3 != undefined) {
        if ((card1 == card2) || (card2 == card3) || (card1 == card3)) {
            return false;
        } else if (!featureCheck(card1.color, card2.color, card3.color)) {
            return false;
        } else if (!featureCheck(card1.texture, card2.texture, card3.texture)) {
            return false;
        } else if (!featureCheck(card1.number, card2.number, card3.number)) {
            return false;
        } else if (!featureCheck(card1.shape, card2.shape, card3.shape)) {
            return false;
        }
        return true;
    }
    return false;
}

// checks whether the features at index parameters satisfy the requirements to make a set
function featureCheck (feature1, feature2, feature3) {
    // if all features are the same, they form a set
    if ((feature1 == feature2) && (feature2 == feature3)) {
        return true;
    }
    // if all features are different, they also form a set 
    else if ((feature1 != feature2) && (feature2 != feature3) && (feature1 != feature3)) {
        return true;
    }
    
    // they don't form a set if they don't meet the previous requirements
    return false;
}


// checks & returns whether a set exists in the diplayed cards
function setExists() {
    for (var i = 0; i < displayedCards.length; i++) {
        for (var j = 0; j < displayedCards.length; j++) {
            for (var k = 0; k <displayedCards.length; k++) {
                if (isSet(i+1, j+1, k+1)) {
                    return true;
                }
            }
        }
    }
    return false;
}

// gives a hint from the displaying set
function getHint() {
    for (var i = 0; i < displayedCards.length; i++) {
        for (var j = 0; j < displayedCards.length; j++) {
            for (var k = 0; k <displayedCards.length; k++) {
                if (isSet(i+1, j+1, k+1)) {
                    document.getElementById("hint").innerHTML = "Hint: " + (i+1) + ", " + (j+1) + ", " + (k+1);
                    return ;
                } 
            }
        }
    } 
}

// updating the HTML GUI: displaying how many sets have been found and how many mare left
function updateSetCount() {
    setsLeft -= 1;
    setsFound += 1;
    document.getElementById("setsFound").innerText = "Sets Found: " + setsFound + " / 27";
}


// renders the cards before the game starts

function renderCards() {
    var disp_cards = document.getElementById('displayedCards');
    if (displayedCards.length > 12){
        disp_cards.setAttribute('class', 'displayedCards2');
    } else {
        disp_cards.setAttribute('class', 'displayedCards');
    }
    disp_cards.innerHTML = '';
    for(var i = 0; i < displayedCards.length; i++) {
            var outside = document.createElement("div");
            outside.classList.add("outer_card");
            var card = document.createElement("div");
            var icon = '';
            if (displayedCards[i] != null) {
                if (displayedCards[i].shape == 'oval')
                if (displayedCards[i].texture == 'open') {
                    icon = '&#11053;';
                }
                else if (displayedCards[i].texture == 'striped'){
                    icon = '&#9677;';
                }
                else {
                    icon = '&#11052;';
                }
            else if (displayedCards[i].shape == 'squiggle')
                if (displayedCards[i].texture == 'solid')
                    icon = '&#8767;';
                else if (displayedCards[i].texture == 'striped')
                    icon = '&#8769;';
                else
                    icon = '&#1150;';
            else
                if (displayedCards[i].texture == 'solid') {
                    icon = '&diams;';
                }
                else if (displayedCards[i].texture == 'striped')
                    icon = '&#10208;';
                else
                    icon = '&#9826;';

            if (displayedCards[i].number == "1")
                card.innerHTML = '<br>' + icon;
            else if (displayedCards[i].number == "2")
                card.innerHTML = icon + '<br>' + '<br>' + icon;
            else
                card.innerHTML = icon + '<br>' + icon + '<br>' + icon;
            
            card.classList.add('card');
            card.classList.add(displayedCards[i].color);
            
            let button1 = document.createElement("button");
            button1.id = i + 1;
            button1.classList.add("button");
            button1.innerText = String(i+1);
            button1.style.height = "40px";
            button1.style.width = "40px";
            button1.style.border = "2px solid black";
            
            outside.appendChild(card);
            outside.appendChild(button1);
            document.getElementById("displayedCards").appendChild(outside);
        }
    }
    // each button calls the clicked() function when they are clicked 
    // each button calls the clicked() function when they are clicked
    if (displayedCards.length > 0) {
        document.getElementById("1").onclick = function() {clicked("1")};
        document.getElementById("2").onclick = function() {clicked("2")};
        document.getElementById("3").onclick = function() {clicked("3")};
        if (displayedCards.length > 3) {
            document.getElementById("4").onclick = function() {clicked("4")};
            document.getElementById("5").onclick = function() {clicked("5")};
            document.getElementById("6").onclick = function() {clicked("6")};
            if (displayedCards.length > 6) {
                document.getElementById("7").onclick = function() {clicked("7")};
                document.getElementById("8").onclick = function() {clicked("8")};
                document.getElementById("9").onclick = function() {clicked("9")};
                if (displayedCards.length > 9) {
                    document.getElementById("10").onclick = function() {clicked("10")};
                    document.getElementById("11").onclick = function() {clicked("11")};
                    document.getElementById("12").onclick = function() {clicked("12")};
                    if (displayedCards.length > 12) {
                        document.getElementById("13").onclick = function() {clicked("13")};
                        document.getElementById("14").onclick = function() {clicked("14")};
                        document.getElementById("15").onclick = function() {clicked("15")};
                        if (displayedCards.length > 15) {
                            document.getElementById("16").onclick = function() {clicked("16")};
                            document.getElementById("17").onclick = function() {clicked("17")};
                            document.getElementById("18").onclick = function() {clicked("18")};
                        }
                    }
                }
            }
        }
    }
}

/* ----------------------------- */

var setsLeft = 27;
var setsFound = 0;

// displaying how many sets have been found
document.getElementById("setsFound").innerText = "Sets Found: " + setsFound + " / 27";

var cards = [];
var colors = ["red", "green", "purple"];
var textures = ["solid", "open", "striped"];
var numbers = ["1", "2", "3"];
var shapes = ["oval", "diamond", "squiggle"];

// creating a deck in order
var i = 0;
for (var a = 0; a < 3; a++) {
    for (var b = 0; b < 3; b++) {
        for (var c = 0; c < 3; c++) {
            for (var d = 0; d < 3; d++) {
                cards[i] = new Card(colors[a], textures[b], numbers[c], shapes[d]);
                i++;
            }  
        }
    }   
}

var nums = [];
var numsRandomOrder = [];
var selectedCards = [];
var selectedCardCount = 0;
var deck = [];

// only used for shuffling purposes... nums contains numbers 1 through 81
for (var i = 1; i <= 81; i++) {
    nums[i-1] = i;
}

// shuffling lol
for (var i = 0; i < 81; i++) {
    var randomNum = Math.floor(Math.random() * 81)+1;
    var check = nums.indexOf(randomNum);

    while (check == -1){
        randomNum = Math.floor(Math.random() * 81)+1;
        check = nums.indexOf(randomNum);
    } 

    numsRandomOrder.push(randomNum);    
    deck.push(cards[randomNum-1]); 

    check = nums.indexOf(randomNum);

    if (check != -1) {
        var index = nums.indexOf(randomNum);
        var firstHalf = nums.slice(0, index);
        var secondHalf = nums.slice(index+1);

        nums = firstHalf.concat(secondHalf);
    }
}

// dealing
var displayedCards = [];
for (var i = 1; i <= 12; i++) {
    var card = deck.pop();
    displayedCards.push(card);
}   

// checks if a set exists and if not, deals 3 more cards
if (!setExists()){
    dealExtra3();
}

// renders the cards before the game begins
renderCards();