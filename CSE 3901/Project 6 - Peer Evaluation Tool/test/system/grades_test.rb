require "application_system_test_case"

class GradesTest < ApplicationSystemTestCase
  setup do
    @grade = grades(:one)
  end

  test "visiting the index" do
    visit grades_url
    assert_selector "h1", text: "Grades"
  end

  test "should create grade" do
    visit grades_url
    click_on "New grade"

    fill_in "Assignment", with: @grade.assignment
    fill_in "Date", with: @grade.date
    fill_in "Feedback", with: @grade.feedback
    fill_in "Score", with: @grade.score
    click_on "Create Grade"

    assert_text "Grade was successfully created"
    click_on "Back"
  end

  test "should update Grade" do
    visit grade_url(@grade)
    click_on "Edit this grade", match: :first

    fill_in "Assignment", with: @grade.assignment
    fill_in "Date", with: @grade.date
    fill_in "Feedback", with: @grade.feedback
    fill_in "Score", with: @grade.score
    click_on "Update Grade"

    assert_text "Grade was successfully updated"
    click_on "Back"
  end

  test "should destroy Grade" do
    visit grade_url(@grade)
    click_on "Destroy this grade", match: :first

    assert_text "Grade was successfully destroyed"
  end
end
