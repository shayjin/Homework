require_relative 'animation'

# returns true if features of 3 cards given as paratmers satisfy a set
def feature_check(card1, card2, card3)
  result  = false

  # checks if all 3 cards have the same feature
  if card1 == card2 && card2 == card3
    result = true

  # checks if all 3 cards have different features
  elsif card1 != card2 && card2 != card3 && card1 != card3
    result = true
  end
  
  return result
end

# checks if 3 cards given as a parameters form a set
def is_set?(card1, card2, card3)
  
  result = true

  # returns false if any 2 or more of the 3 cards are the same
  result = false if card1.equal? card2 or card1.equal? card3 or card2.equal? card3
  if result
     # checks if 3 cards have all 4 features that satisfy a set
     result = false unless feature_check(card1.color, card2.color, card3.color)
     result = false unless feature_check(card1.number, card2.number, card3.number)
     result = false unless feature_check(card1.shading, card2.shading, card3.shading)
     result = false unless feature_check(card1.symbol, card2.symbol, card3.symbol)
  end
  
  return result
end

# checks if at lesat 1 set exists in the deck given as a parameter
def set_exists?(deck)
  result = false
  # loops through the entire deck
  for i in 0..deck.length()-1 do
    for j in 0..deck.length()-1 do
      for k in 0..deck.length()-1 do
        # checks if a set exists
        result = true if is_set?(deck[i], deck[j], deck[k])
      end
    end
  end
  return result
end

# gives a hint if user asks for it
def get_hint(deck)
  # animation
  anime1
  anime2
  # only gives out a hint if there are 9 or more cards on the table
  if deck.length() >= 9
    # loops through the entire deck on the table
    for i in 0..deck.length()-1 do
      for j in 0..deck.length()-1 do
        for k in 0..deck.length()-1 do
          # if a set is found, it gives 2 of the members of the set
          if is_set?(deck[i], deck[j], deck[k])
            puts "| [#{j+1}] is part of a set...."
            print "| [#{k+1}] is part of a set...."
            return
          end
        end
      end
    end

  # doesn't givec out hint if there are 9 or more cards on the table
  else
    puts "You have less than 3 sets remaining! Try harder!"
  end
end


