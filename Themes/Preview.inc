[Preview_Hidden]
Meter=Image
PreserveAspectRatio=1
ImageAlpha=0
X=10
Y=10R
W=([SkinSizing:W]-20)
ImageName="%LocalAppData%\Microsoft\Windows\Themes\RoamedThemeFiles\DesktopBackground\transcodedwallpaper.jpg"
UpdateDivider=-1

[Preview_Border]
Meter=Image
X=0r
Y=0r
W=([SkinSizing:W]-20)
H=([Preview_Hidden:H]+5)
SolidColor=0,0,0
DynamicVariables=1

[Preview_Background]
Meter=Image
PreserveAspectRatio=1
ImageAlpha=255
X=10r
Y=10r
W=([Preview_Border:W]-2*10)
ImageName="%LocalAppData%\Microsoft\Windows\Themes\RoamedThemeFiles\DesktopBackground\transcodedwallpaper.jpg"
UpdateDivider=-1

[Preview_Skin_Background]
Group=Preview
Meter=Image
X=20r
Y=20r
W=([Preview_Background:W]-2*20)
H=([Preview_Background:H]-2*20)
DynamicVariables=1
SolidColor=#BackgroundColor#
UpdateDivider=-1

[Preview_Skin_ForegroundTL]
Group=Preview
Meter=String
ClipString=2
FontColor=#ForegroundColor#
StringAlign=LeftTop
X=15r
Y=15r
W=([Preview_Skin_Background:W]-2*15)
DynamicVariables=1
Text=Lorem ipsum dolor sit amet, consectetur adipiscing elit
UpdateDivider=-1

[Preview_Skin_ForegroundBR]
Group=Preview
Meter=String
ClipString=2
FontColor=#ForegroundColor#
StringAlign=RightBottom
X=([Preview_Background:X]+[Preview_Background:W]-30)
Y=([Preview_Background:Y]+[Preview_Background:H]-30)
W=([Preview_Skin_Background:W]-2*15)
DynamicVariables=1
Text=Lorem ipsum#CRLF#dolor sit amet, consectetur adipiscing elit
UpdateDivider=-1

[PreviewTest]
Measure=Calc
Formula=50
MaxValue=100

[Preview_Skin_ForegroundCC]
Group=Preview
Meter=Bar
MeterStyle=BarStyle
X=(([Preview_Background:X]-30+[Preview_Background:W]/2))
Y=(([Preview_Background:Y]+[Preview_Background:H]/2))
W=115
H=20
MeasureName=PreviewTest
DynamicVariables=1
UpdateDivider=-1
