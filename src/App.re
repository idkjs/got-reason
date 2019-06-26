Utils.requireCSS("./App.css");

[@react.component]
let make = () => {
  let (selectedCharacter, setSelectedCharacter) = React.useState(() => None);

  let handleSelected = character => {
    setSelectedCharacter(_ => Some(character));
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