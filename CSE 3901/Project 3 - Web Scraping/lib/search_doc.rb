require 'nokogiri'
require './lib/search_ul'

class Search_doc
    
    # Searches through all of the <ul> in the html and returns a pair of a list with the 
    # categories found and a list of all the courses on each category.
    def search(doc)
        categories = []
        courses = []
        # searching through all the <ul> in the doc
        doc.search('div.content-body.content-type-page ul').each do |a|
            # updating categories and courses
            Search_ul.new.search(a, categories, courses)
        end
        [categories, courses]
    end
end