class AddEvalutorFieldToGrade < ActiveRecord::Migration[7.0]
  def change
    add_column :grades, :evaluator, :string
  end
end
