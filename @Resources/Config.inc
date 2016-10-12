[Metadata]
Name=Config
Author=Lucky Penny
Information=Meters used on components to access the settings
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

[SkinSizing]
MouseOverAction=!ShowMeter MeterConfig
MouseLeaveAction=!HideMeter MeterConfig

[MeterConfig]
Meter=String
X=([SkinSizing:W]-5)
Y=5
W=8
H=8
StringAlign=Right
FontSize=10
FontColor=#ForegroundColor
Text=*
AntiAlias=1
DynamicVariables=1
UpdateDivider=-1
ToolTipText=Settings
LeftMouseUpAction=[!ToggleConfig "#CurrentConfig#\Config" "Config.ini"]
Hidden=1
