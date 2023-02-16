class AddCourseToUser < ActiveRecord::Migration[7.0]
  def change
    add_column :users, :course, :string
  end
end
