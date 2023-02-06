# project5-group5
- Members: Jay Shin, Robbie Rogers, Klejdi Vrekaj, Riley Gillman

# Program Description
- This program contains the game of set. 
- There are 81 unique cards in the deck for the game of set
- There are four features to each card: number of shapes (1, 2, or 3), shape (diamond, squiggle, or oval), shading (solid, stripped, or open), and color (red, green, or purple)
- 12 of these cards will be shown at a time
- A card will be shown and a corresponding button to that card in the format: color, shading, number of shapes, shape
    - the color will be either 'red ', 'grn ', or 'prpl'
    - the shadding will be 'solid', 'strip', or 'open '
    - the number will be '1', '2', or '3'
    - the shape will be '<>', '~ ', or 'O'
- Some shape icons used in the game:
    - Ѿ represents an open squiggle
    - ≁ represents a striped squiggle
    - ∿ represents a solid squiggle
    - ◍ represents a striped oval
    - ⟠ represents a striped diamond
    and the rest are trivial.
- Some example cards:
    - red, striped, 1, diamond
    - purple, solid, 2, squiggle
    - green, open, 3, oval
- Buttons will also have a number corresponding to the cards which will be used to pick sets
- Once the card is chosen, the card chosen will be dispayed below the buttons and keep displaying until 3 cards are chosen
- Once three cards are chosen then it will show you the status "That was not a set!" or "That was a set!"
- If needed there is a "Get Hint" Button
- At the bottom it will keep track of the amount of sets left and the amount of sets found
- The goal is to make a 'set' from 3 of the cards
- A set is any 3 cards that satisfy all of the following conditions:
    - They all have the same number or have three different numbers
    - They all have the same shape or have three different shapes
    - They all have the same shading or have three different shadings
    - They all have the same color or have three different colors
- The only combination of the above conditions is that they cannot all be the same as every card is unique

# Program Controls
- To run this program, run the program with "firefox index.html" in the terminal
