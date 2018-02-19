let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("TestButton");
let make = (~name, _children) => {
  ...component,
  render: (_self) => <button> {str(name)} </button>
};
