MRuby::Build.new do |conf|
  toolchain :gcc
  conf.gembox 'default'
  conf.gem 'mrb-bin-example'
end
