Utils.requireCSS("./CharacterDetail.css");

[@react.component]
let make = (~character, ~onChangeCharacter) => {
  // Js.log2("CHARACTER: ", character);
  Js.log2("CHARACTER##APPEAREDIN: ", character##appearedIn);

  let handleClick = id => {
    onChangeCharacter(id);
  };

  // let test =
  //   switch (character##father) {
  //   | Some(father) =>
  //     let name = Some(father##name);
  //     let name2 = father##name;
  //     let id = Some(father##id);
  //     Js.log2("FATHER_TEST_NAME: ", name);
  //     Js.log2("FATHER_TEST_NAME2: ", name2);
  //     Js.log2("FATHER_TEST_ID: ", id);
  //   | None => "NO_FATHER"->Js.log
  //   };

  let renderItem = (~label: string, ~item) => {
    switch (item) {
    | Some(item) =>
      <div> <strong> label->React.string </strong> item->React.string </div>
    | None => React.null
    };
  };

  let renderListItem = (~label: string, ~items: option('a)) => {
    switch (items) {
    | Some(items) =>
      <div> <strong> label->React.string </strong> </div>;
      React.array(
        Belt.Array.map(items, i => <div> {i |> React.string} </div>),
      );
    | None => React.null
    };
  };
  Js.log2("CHARACTER##children: ", character##children);
  // {
  //   Array.length(character##children) |> Js.log;
  // };
  // {
  //   Js.Array.length(character##children) > 0 |> Js.log;
  // };

// {character##appearedIn ? Js.log(Some(character##appeaeredIn)) : Js.log("false")};
  let renderCharacter = (~label: string, ~c) => {
    switch (c) {
    | Some(c) =>
      let name = c##name;
      let id = c##id;
      <div>
        <strong> label->React.string </strong>
        <a href="#" onClick={_e => handleClick(id)}> name->React.string </a>
      </div>;
    | None => React.null
    };
  };
  <>
    <h2> {character##name |> React.string} </h2>
    {switch (character##allegiances) {
     | Some(allegiances) =>
       React.array(
         Belt.Array.map(allegiances, a =>
           <div> {"Loyal to " ++ a##name |> React.string} </div>
         ),
       )
     | None => React.null
     }}
    {renderItem("Culture", character##culture)}
    {renderItem("Played by: ", character##playedBy)}
    {renderListItem("Aliases: ", character##aliases)}
    {renderListItem("Titles: ", character##titles)}
    {renderItem("Born: ", character##born)}
    {renderItem("Died: ", character##died)}
    {renderItem("Culture: ", character##culture)}
    {renderCharacter("Father: ", character##father)}
    {renderCharacter("Mother: ", character##mother)}
    {renderCharacter("Spouse: ", character##spouse)}
    {switch (character##children) {
     | Some(children) =>
       <div>
         <strong> {"Children" |> React.string} </strong>
         <br />
         {React.array(
            Belt.Array.map(children, c =>
              <>
                <a href="#" onClick={_e => handleClick(c##id)}>
                  {c##name->React.string}
                </a>
                <br />
              </>
            ),
          )}
       </div>
     | None => React.null
     }}
    // {switch (character##appearedIn) {
    //  | Some(appearedIn) =>{
    //    let names = Js.Array.map( c => c##name);
    //    Js.log(names);
    //    <div>
    //      <strong> {"Appeared In: " |> React.string} </strong>
    //      <br />
    //      {
    //         Js.Array.map( name =>
    //           <>
    //               {name->React.string}
    //             <br />
    //           </>,
    //           names
    //         )
    //         |> React.array
    //       }
    //    </div>}
    //  | None => React.null
    //  }
    //  }
    {switch (character##books) {
     | Some(books) =>
       <div>
         <strong> {"Books: " |> React.string} </strong>
         <br />
         {React.array(
            Belt.Array.map(books, c =>
              <>
                  {c##name->React.string}
                <br />
              </>,
            ),
          )}
       </div>
     | None => React.null
     }}

    //  {renderListItem("Character appeared in", character##appearedIn)}
    //   {switch (character##father) {
    // | Some(father) =>
    //   let name = father##name;
    //   let id = father##id;
    //   <div>
    //       <strong> "Father: "->React.string </strong>
    //       <a href="#" onClick={_e => handleClick(id)}> {name->React.string} </a>
    //     </div>;
    // | None => React.null
    // }}
    //   {switch (character##mother) {
    // | Some(mother) =>
    //   let name = mother##name;
    //   let id = mother##id;
    //   <div>
    //       <strong> "Mother: "->React.string </strong>
    //       <a href="#" onClick={_e => handleClick(id)}> {name->React.string} </a>
    //     </div>;
    // | None => React.null
    // }}
    //   {switch (character##spouse) {
    // | Some(spouse) =>
    //   let name = spouse##name;
    //   let id = spouse##id;
    //   <div>
    //       <strong> "Spouse: "->React.string </strong>
    //       <a href="#" onClick={_e => handleClick(id)}> {name->React.string} </a>
    //     </div>;
    // | None => React.null
    // }}
  </>;
};