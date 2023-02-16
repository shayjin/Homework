require 'nokogiri'

class Search_ul

    #initializing index and dump as class scope variables
    @@index = -1
    @@dump = 0

    # this method searches through a <ul> and updates categories and courses for each category
    def search(a, categories, courses)
        categories_size = 7
        ul = Nokogiri::HTML5(a)

        # whenever there is a new a, the next x will be fhe first required class in the category
        first = true
        # searches through all of the <li> in the currents <ul>
        ul.search('li').each do |x|
            # extracting all of the categories and storing in an array
            if categories.size < categories_size then
                category = x.inner_text.strip
                categories << category
                courses.push([])
            else
                # printing the cateogory when x is the first required class in the category
                if first and @@dump == 0 then
                    @@index += 1
                    first = false
                end
    
                # extracting a course in the category
                course = x.inner_text.strip
    
                # when there is a <ul> within a <li> it always contains the word "Choose"
                if course.to_str.include? "Choose" then
                        nested = Nokogiri::HTML5(x)
    
                        # counts the number of ocurrences of <li> within a <li>
                        nested.search('li').each do |n|
                            @@dump += 1
                        end
    
                        # doesn't count the parent <li>
                        @@dump -= 1
                        
                        # add the course to courses
                        courses[@@index].push(course)
                        break
    
                # skips adding the course to courses when @@dump is not equal to 0
                elsif @@dump == 0
                    courses[@@index].push(course)
                end
    
                # when @@dump is not equal to 0, the program doesn't print anything and decrements @@dump by 1
                if @@dump != 0 then
                    @@dump -= 1
                end
            end
        end 
    end
end