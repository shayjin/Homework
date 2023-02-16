class AddGroupToGrades < ActiveRecord::Migration[7.0]
  def change
    add_column :grades, :evaluator_group, :string
  end
end
