require 'nokogiri'
require 'open-uri'
require './lib/search_doc'
require './lib/user_interface'

# loading the html from the url into doc
doc = Nokogiri::HTML(URI.open('https://cse.osu.edu/current-students/undergraduate/majors/bs-cse/bs-cse-curriculum'))

puts "\n~~~~~~~ Ohio State Computer Science and Engineering Course Requirements ~~~~~~~\n\n"

# getting all the categories and their respective courses
categories, courses = Search_doc.new.search(doc)

# engaging with the user
User_interface.new(categories, courses)

puts "\nGoodbye!\n\n"