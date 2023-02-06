class User_interface

    # initializes a UI that shows the categories, asks the user to choose a category
    # and prints the courses of the selected category
    def initialize(categories, courses)
        # displaying categories
        for i in 0..categories.size-1 do
            puts "[#{i+1}] #{categories[i]}"
        end

        # gets user input
        print"\nWhich category of courses would you like to see?: "
        input = gets.to_i

        while input.between?(1, categories.size) do
            # displaying category
            puts ""
            puts "[#{input}] #{categories[input-1]}"
            60.times do
                print "-"
            end
            puts ""
            puts courses[input-1]
            # ask for input
            print "\nWhich category of courses would you like to see?: "
            input = gets.to_i
        end
    end
end