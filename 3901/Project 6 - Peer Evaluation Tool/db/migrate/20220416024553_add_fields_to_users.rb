class AddFieldsToUsers < ActiveRecord::Migration[7.0]
  def change
    add_column :users, :job, :string
  end
end
