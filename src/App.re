Utils.requireCSS("./App.css");

[@react.component]
let make = () => {
    let (selectedCharacter, setSelectedCharacter) = React.useState(() => None);

    let handleSelected = character => {
        Js.log2("handleSelected_APP",character);
              setSelectedCharacter(_ => Some(character));
        Js.log2("handleSelected_APP_TERM",selectedCharacter);
      };
  <div className="App">
    <header className="App-header">
      <h1> {"An app of the seven kingdoms" |> React.string} </h1>
    </header>
    <div className="Character-wrapper">
          <CharacterList onChangeCharacter=handleSelected />
          <CharacterDetail selectedCharacter onChangeCharacter=handleSelected />
    </div>
  </div>;
};