type action =
  | Click
  | Toggle;

type state = {
  count: int,
  show: bool
};

let component = ReasonReact.reducerComponent("MyForm");

let make = (_children) => {
  ...component,
  initialState: () => {count: 0, show: false},
  reducer: (action, state) =>
    switch action {
    | Click => ReasonReact.Update({...state, count: state.count + 1})
    | Toggle => ReasonReact.Update({...state, show: ! state.show})
    },
  render: (self) => {
  let message = "Clicked " ++ string_of_int(self.state.count) ++ " times";
    <div>
      <div onClick=(self.reduce((_event) => Click))
        onSubmit=(self.reduce((_event) => Toggle))>
        (ReasonReact.stringToElement("Click"))
      </div>
      <div onClick=(self.reduce((_event) => Toggle))>
        (ReasonReact.stringToElement("Hide"))
      </div>
      {ReasonReact.stringToElement(message)}
    </div>
  }
};
