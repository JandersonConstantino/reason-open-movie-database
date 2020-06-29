module Styles = {
  open Css;

  let containerInput = style([
    border(px(2), solid, hex("c4c4c4")),
    borderRadius(px(8)),
    width(vw(70.0))
  ]);

  let input = style([
    backgroundColor(transparent),
    fontSize(px(25)),
    borderColor(transparent),
    margin(px(10)),
    outline(px(0), solid, transparent),
    textAlign(center),
    width(`percent(100.0))
  ]);

  let container = style([
    display(`flex),
    flexWrap(`wrap),
    maxWidth(vw(70.0)),
    justifyContent(`center),
    marginTop(px(100))
  ]);

  let item = style([
    minWidth(`percent(20.0)),
    maxWidth(`percent(20.0)),
    flex(`num(1.0)),
    margin(px(10)),
    textAlign(`center),
    fontSize(`em(1.5)),
    borderRadius(px(4)),
  ]);

  let title = style([
    display(`block),
    marginTop(px(20)),
  ]);

  let image = style([
    maxWidth(`percent(100.0)),
    height(`percent(70.0)),
    borderRadius(px(8)),
    objectFit(`contain),
  ])
};
