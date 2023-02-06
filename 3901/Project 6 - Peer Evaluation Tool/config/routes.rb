Rails.application.routes.draw do
  resources :assignments
  resources :courses
  resources :groups
  devise_for :users
  resources :grades
  resources :texts
  resources :feedbacks
  get 'home/grades'
  get 'home/assignments'
  get 'grades/new'
  get 'grades/index'
  get 'grades/thead'
  get 'grades/show'
  get 'home/roster'
  root 'home#index'
  

  # Define your application routes per the DSL in https://guides.rubyonrails.org/routing.html

  # Defines the root path route ("/")
  # root "articles#index"
end
