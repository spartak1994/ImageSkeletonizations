object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1057#1082#1077#1083#1077#1090#1080#1079#1072#1094#1080#1103' '#1084#1077#1090#1086#1076#1086#1084' '#1065#1077#1087#1080#1085#1072
  ClientHeight = 566
  ClientWidth = 616
  Color = clGradientActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object BitBtn1: TBitBtn
    Left = 472
    Top = 328
    Width = 75
    Height = 25
    Caption = 'Go'
    TabOrder = 0
    OnClick = BitBtn1Click
  end
  object Edit1: TEdit
    Left = 472
    Top = 240
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '10'
  end
  object Timer1: TTimer
    Interval = 10
    OnTimer = Timer1Timer
    Left = 560
    Top = 56
  end
end
