MRuby::Gem::Specification.new('mruby-bin-example') do |spec|
  spec.license = 'MIT'
  spec.author  = 'Aotokitsuruya'
  spec.summary = 'concourse example command'

  spec.bins = %w(example)
  spec.add_dependency('mruby-compiler', :core => 'mruby-compiler')
end
