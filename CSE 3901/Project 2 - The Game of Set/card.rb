require_relative "game"
require_relative "board"

# this class represents a card
class Card

  attr_accessor :number, :symbol, :shading, :color

  # creates initializes a card with 4 features: number, symbol, color, and shading
  def initialize (number = nil, symbol = nil, color = nil, shading = nil)
        @number = number
        @symbol = symbol
        @shading = shading
        @color = color
  end

  # converts a card into a string
  def to_s
   "#{@number}, #{@symbol}, #{@shading}, #{@color}"
  end

  # returns the length of the card in as a string
  def length
    return self.to_s.length()
  end
  
end

  
