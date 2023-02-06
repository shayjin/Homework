require_relative 'card'
require_relative 'deck'
require_relative 'board'
require_relative 'animation'

# this class represents the game flow
def game
  # creates a new shuffled deck
  deck = Deck.new
  
  # represents a showing cards on the table
  displayed_cards = Array.new

  # variable that shows how many sets are left for user to find
  sets_remaining = 27

  # puts cards on the table
  for i in 1..12 do
    displayed_cards.push(deck.draw)
  end

  # animation
  anime1
  anime2
  
  puts "|    Find a set! (Sets Remaining: #{sets_remaining})  |"

  # game starts and loops until you win the game
  loop do
    # temporary array
    t = Array.new
    
    anime2

    # displays the cards on the table
    for i in 0..displayed_cards.length()-1
      if !displayed_cards[i].is_a?(NilClass)
        print "|    [#{i+1}] #{displayed_cards[i]}"
        t.push(displayed_cards[i])

        # adds spacing for the grpahics
        if i < 9
          for j in 1..30-displayed_cards[i].length do
            print " "
          end
        else
          for j in 1..29-displayed_cards[i].length do
            print " "
          end
        end
        puts "|"
      end
    end

    # draws 3 more cards if there are no sets on the table
    unless set_exists?(t) or t.length() < 9
      3.times {
        new_card = deck.draw
        t.push(new_card)
        displayed_cards.push(new_card)
        puts "|    [#{displayed_cards.length()}] #{displayed_cards[displayed_cards.length()-1]}"
        
        
      }
    end

    # animation
    anime2
    anime1
    anime2

    # gets the first card
    print "|    first (Enter 0 to get a hint):    "
    first = gets.to_i()

    # draw = nil

    # gives a hint
    if first == 0
      anime2
      puts get_hint(t)
      anime2

    # gets the second and third cards
    else
      print "|    Second:                           "
      second = gets.to_i()
      print "|    third:                            "
      third = gets.to_i()
      anime2
      # checks if the 3 cards user entered form a set and whether you should discard and draw new cards
      draw = is_set?(t[first-1], t[second-1], t[third-1])
    end

    # animation...
    anime1
    anime2
     # doesn't do anything if user input is invalid
    if first.between?(1,81) and second.between?(1,81) and third.between?(1,81)
      draw = false
    end
    if draw and displayed_cards.length() <= 12 and sets_remaining > 4

      # sorts the 3 cards in ascending order because ruby 3.0 doesn't have a .sort method I think
      while (first > second or second > third)
        if first > second
          temp = first
          first = second
          second = temp
        end
        if second > third
          temp = second
          second = third
          third = temp
        end
      end
      
      # removes the 3 cards from the table
      displayed_cards.delete_at(first-1)
      displayed_cards.delete_at(second-2)
      displayed_cards.delete_at(third-3)

      # draws 3 cards from the deck
      if displayed_cards.length() < 12
        displayed_cards.push(deck.draw)
        displayed_cards.push(deck.draw)
        displayed_cards.push(deck.draw)
      end

      # minus 1 from sets remaining
      sets_remaining -= 1
      puts "|  Nice! You found a set!              |"

     # if there are no more cards to draw, it just removes 3 cards from the table
     elsif draw and (sets_remaining <= 4 or displayed_cards.length() > 12)
       displayed_cards.delete_at(first-1)     
       displayed_cards.delete_at(second-2)    
       displayed_cards.delete_at(third-3)

       # minus 1 from sets remaining
       sets_remaining -= 1
       puts "|  Nice! You found a set!              |"

      
      # doesn't do anything if the 3 cards don't form a set
     elsif first.between?(1, 81) and !draw
       puts "|    That is not a set... Try again!     |"
     end

      # shows how many sets are found and how amny are remaining
      if 27 - sets_remaining >= 10 and sets_remaining >= 10
        puts "|  Sets Found: #{27-sets_remaining} Sets Remaining: #{sets_remaining}   |"
      else
        puts "|  Sets Found: #{27-sets_remaining} Sets Remaining: #{sets_remaining}    |"
      end

      #animation
      anime2
      anime1

    # if no cards are on the table or 
    if sets_remaining == 0 or (!set_exists?(displayed_cards) and displayed_cards.length() <= 9)
      puts ""
      anime1
      anime2
      puts "|    Congruations! You won the game!   |"
      anime2
      break
    end
  end
end

  
