object Main: TMain
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsNone
  Caption = #1044#1077#1090#1089#1082#1086#1077' '#1087#1088#1080#1083#1086#1078#1077#1085#1080#1077
  ClientHeight = 402
  ClientWidth = 602
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesigned
  WindowState = wsMaximized
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyUp = FormKeyUp
  OnMouseUp = FormMouseUp
  DesignSize = (
    602
    402)
  PixelsPerInch = 96
  TextHeight = 13
  object lblChar: TLabel
    Left = 272
    Top = 128
    Width = 81
    Height = 160
    Caption = #9166
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -133
    Font.Name = 'Tahoma'
    Font.Style = []
    Font.Quality = fqAntialiased
    ParentFont = False
    Visible = False
    OnMouseUp = FormMouseUp
  end
  object btnClose: TButton
    Left = 496
    Top = 8
    Width = 98
    Height = 57
    Anchors = [akTop, akRight]
    Caption = 'CLOSE'
    TabOrder = 0
    Visible = False
    OnClick = btnCloseClick
  end
end
