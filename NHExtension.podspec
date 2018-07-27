#
#  Be sure to run `pod spec lint NHExtension.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "NHExtension"
  s.version      = "1.1.0"
  s.summary      = "UIKit、Foundation的类扩展."
  s.description  = <<-DESC
  常用的UIKit、Foundation的类扩展
                   DESC
  s.homepage     = "https://github.com/neghao/NHExtension.git"

  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author       = { "neghao_pro" => "neghao@126.com" }

  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/neghao/NHExtension.git", :tag => "#{s.version}" }

  s.source_files = 'NHExtension/**/*.{h,m}'

  s.frameworks   = "UIKit", "Foundation", "ImageIO"

  s.libraries    = "z"

  s.requires_arc = true

 s.dependency 'DZNEmptyDataSet'
 s.dependency 'UIView+MGBadgeView'



  # s.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }

end
