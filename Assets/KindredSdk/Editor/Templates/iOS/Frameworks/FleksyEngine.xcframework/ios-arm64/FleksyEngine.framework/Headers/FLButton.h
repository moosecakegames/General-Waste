//
//  FLButton.h
//  FleksyEngine
//
//  Created by Dennis Horte on 12/31/14.
//  Copyright (c) 2014 Thingthing, Ltd. All rights reserved.
//

#ifndef FleksyEngine_FLButton_h
#define FleksyEngine_FLButton_h

#include <cmath>
#include "FLEnums.h"
#include <FleksyCore/FLPoint.h>
#include <FleksyCore/FLUnicodeString.h>
#include <unordered_map>

class FLButton {
public:
  class Rect{
  public:
    double left = 0;
    double top = 0;
    double right = 0;
    double bottom = 0;

    double getWidth() const {
      return std::abs(right - left);
    }
    double getHeight() const {
      return std::abs(bottom - top);
    }
  };

  FLButton();
  FLButton(const FLUnicodeString &label_, FLButtonType buttonType_);

  FLButtonType buttonType;
  /**
   Vector of labels for the button. Index zero is the primary label.
   Other indices may contain accents.
   Platform can ignore these, they are used to determine what
   alternative keyboard to present by the engine.
   */
  std::vector<FLUnicodeString> labels;
  FLPoint centerPoint;
  Rect boundingRect;
  
  /**
   Hint to be shown in the button
   */
  FLUnicodeString _hint;

  float weight = -1;
  int uniqueID = -1;
  bool isTransparent = true;
  bool isDiagonal = false;
  bool isOnTempLayout = false;
  bool isActive = true;
  FLKeyboardID keyboardID; //ID of the keyboard this button is on

  bool isLetterButton() const;
  bool isPunctuationButton() const;
  bool isActionButton() const;
  bool hasLabel(const FLUnicodeString &letter) const;
  bool containsPoint(const FLPoint &p) const;
  bool containsPoint(const FLPoint &p, const unsigned int margin) const;
  void setBoundingRect(FLPoint _centerPoint, const float width, const float height);
  void addAccents(std::vector<FLUnicodeString> accents);
  void setHint(const FLUnicodeString& hint);
  FLUnicodeString toString() const;
  FLUnicodeString getPrimaryLabel() const;
  void setPrimaryLabel(const FLUnicodeString &label);

  FLUnicodeString getHint() const;
  
  static FLButtonType getButtonTypeFromString(const FLUnicodeString &str);

private:
  static const std::unordered_map<FLUnicodeString, FLButtonType, FLUnicodeStringHash, FLUnicodeStringEqual> _stringToButtonTypeMap;
};

#endif /* defined(FleksyEngine_FLButton_h) */
