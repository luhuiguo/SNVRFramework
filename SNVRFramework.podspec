Pod::Spec.new do |s|

  s.name         = "SNVRFramework"
  s.version      = "1.0.0"
  s.summary      = "SNVR Framework"
  s.license      = {
    :type => 'Commercial',
    :text => <<-LICENSE
                Copyright (c) 2015, Daxun Digital Technology Co., Ltd.
                All rights reserved.
    LICENSE
  }
  s.homepage     = "http://www.snvr.cc"

  s.author       = { "Lu Huiguo" => "luhuiguo@gmail.com" }

  s.source  = { :git => "https://github.com/luhuiguo/SNVRFramework.git", :tag => s.version.to_s }

  s.platform = :ios, 7.0

  s.frameworks = 'Foundation', 'UIKit', 'QuartzCore', 'CoreGraphics', 'SNVR'
  
  s.libraries = 'iconv', 'z', 'bz2'

  s.dependency 'CocoaAsyncSocket', '~>7.4.1'

  s.dependency 'CocoaLumberjack', '~>1.9.2'

  s.dependency 'ffmpeg'

  s.vendored_frameworks = 'SNVR.framework'
end
