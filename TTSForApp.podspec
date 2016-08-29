#
# Be sure to run `pod lib lint TTSForApp.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
# 校验sepc可用性 pod spec lint ISCProject.podspec
#

Pod::Spec.new do |s|
  s.name             = 'TTSForApp'  #名称
  s.version          = '0.1.0'      #版本号
  s.summary          = 'TTSForApp is Text To Speech service for didi service.'  #简短介绍

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC   #详细介绍

  s.homepage         = 'https://github.com/<GITHUB_USERNAME>/TTSForApp'  #主页，这里要填写可以访问到的地址，不然验证不通过
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }   #开源协议
  s.author           = { 'guoliting' => 'guoliting@didichuxing.com' }    #作者信息
  s.source           = { :git => 'http://10.93.129.28/glt3953/TTSForApp.git', :tag => s.version.to_s }  #项目地址，这里不支持ssh的地址，验证不通过，只支持HTTP和HTTPS，最好使用HTTPS
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '7.0'  #支持的平台及版本

  s.source_files = 'TTSForApp/Classes/**/*'  #代码源文件地址，**/*表示Classes目录及其子目录下所有文件，如果有多个目录下则用逗号分开，如果需要在项目中分组显示，这里也要做相应的设置
  
  s.resource_bundles = {
      'TTSForApp' => ['TTSForApp/Assets/**/*.dat']   #资源文件地址
  }

  # s.public_header_files = 'Pod/Classes/**/*.h'     #公开头文件地址

    s.vendored_libraries = [
        'TTSForApp/lib/libSpeechSynthesizer.a',
    ]

  # s.frameworks = 'UIKit', 'MapKit'    #所需的framework，多个用逗号隔开
  # s.dependency 'AFNetworking', '~> 2.3'    #依赖关系，该项目所依赖的其他库，如果有多个需要填写多个s.dependency
end
