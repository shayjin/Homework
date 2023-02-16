require_relative 'game'
require_relative 'instructions'
require_relative "card"
require_relative 'animation'

loop do
  # animation
  anime1
  sleep 0.3
  anime2

  # starting screen
  puts "|  Welcome to the Game of Set! Enter:  |"
  sleep 0.3

  puts "|      [1] to play the game.           |"
  sleep 0.3

  puts "|      [2] to view instructions.       |"
  sleep 0.3

  puts "|      [3] exit.                       |"
  sleep 0.3

  # animation
  anime2
  sleep 0.3
  anime1
  anime2

  # asks user for options
  print "|   What would you like to do?:        "

  # gets user input
  choice = gets.chomp()

  # animation
  anime2
  anime1
  anime2

  
  if choice != "1" and choice != "2" and choice != "3"
    # restarts the game
    puts "|          Invalid input!              |"
    anime2
    
  elsif choice == "1"
    # game will start
    game
    
  elsif choice == "2"
    # instructions will be shown
    puts ""
    anime1
    
    puts "Game of set consits of 81 unique cards that vary in 4 features:"
    puts "Number (1, 2, 3), Shape (Diamond, Squiggle, Oval)"
    puts "Shading (Solid, Striped, Open), Color (Red, Green, Blue)"
    puts "Certain combinations of 3 cards make up a set."
    puts "3 cards must diplay that feauture all the same or all different."
    puts "Put anohter way: You must avoid having 2 cards showing the"
    puts "same feature and 1 remaining card showing a different feature."

    anime1
    puts ""
    
    
  elsif choice == "3"
    # game will end
    puts "|     Thank you for playing!           |"

    anime2
    anime1
    exit
  end
  
end
