require_relative "card"

# this class represnets a deck or 81 cards
class Deck

  # creates a deck of all possible cards and shuffles it
  def initialize
    @deck = Array.new
    temp = Card.new

    # assigns numbers 1, 2, and 3
    (1..3).each do |number|
      temp.number = number
      # assigns symbols diamond, oval, and squiggle
      (1..3).each do |symbol|
        temp.symbol = "diamond" if symbol ==  1
        temp.symbol = "oval" if symbol == 2
        temp.symbol = "squiggle" if symbol == 3
        # assigns shadings solid, lines, and empty
        (1..3).each do |shading|
          temp.shading = "solid" if shading == 1
          temp.shading = "lines" if shading == 2
          temp.shading = "empty" if shading == 3
          # assigns colors red, blue, and green
          (1..3).each do |color|
            temp.color = "red" if color == 1
            temp.color = "blue" if color == 2
            temp.color = "green" if color ==3

            # trasnsfers temp to card
            card = Card.new
            card.number = temp.number
            card.symbol = temp.symbol
            card.shading = temp.shading
            card.color = temp.color

            # places a card in the deck
            @deck.push(card)
            
          end
        end
      end
    end
    #randomizies the order of the cards in the deck
    @deck = @deck.shuffle
    
end

# draws a card from the deck
def draw
   @deck.pop
end

end
