Utils.requireCSS("./CharacterDetail.css");

// [@bs.deriving abstract]
// type bookUntyped = {
//   name: string,
//   id: string,
// };

// [@bs.deriving {jsConverter: newType}]
// type book = {
//   name: string,
//   id: string,
// };
[@react.component]
let make = (~character, ~onChangeCharacter) => {
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

  {
    Js.log2("CHARACTER: ", character);
    Js.log2("CHARACTER##BOOKS: ", character##books);
    Js.log2("CHARACTER##CHILDREN: ", character##children);
    Js.log2("CHARACTER##APPEAREDIN: ", character##appearedIn);
    let cities = [%get_in character##appearedIn];
    Js.log2("CHARACTER##CITIES: ", cities);
    Js.log2("LENGTH: ", Belt.Array.length(character##appearedIn));
    Belt.Array.map(cities, city => Js.log(city##name));
    Belt.Array.map(character##appearedIn, city => Js.log(city##name));
    // let items = cities->Belt.Array.keepMap(city => city);
    //     character##appearedIn
    //  ->Belt.Array.keepMap(season => season)
    //  ->Js.log2("CHARACTER##SEASONS: ");
    // let items = character##appearedIn->Belt.Array.keepMap(city => city)->Js.log2("CHARACTER##SEASONS: ");
    // items;
  };
  // // let appearedIn = Belt.Array.(character##appearedIn, [||]);
  // Js.log2("appearedIn: ",appearedIn);
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
    {switch (character##books) {
     | Some(books) =>
       <div>
         <strong> {"Books: " |> React.string} </strong>
         <br />
         {React.array(
            Belt.Array.map(books, c => <> {c##name->React.string} <br /> </>),
          )}
       </div>
     | None => React.null
     }}
    {Belt.Array.length(character##appearedIn) > 0 ? <div>
       <strong> {"TV Seasons: " |> React.string} </strong>
       <br />
       {Belt.Array.map(character##appearedIn, season =>
          <> {season##name->React.string} <br /> </>
        )
        |> React.array}
     </div>: React.null}
    // {<div>
    //    <strong> {"TV Seasons: " |> React.string} </strong>
    //    <br />
    //    {Belt.Array.map(character##appearedIn, season =>
    //       <> {season##name->React.string} <br /> </>
    //     )
    //     |> React.array}
    //  </div>}
    // {character##appearedIn ? <div>
    //        <strong> {"Has Appeared In: " |> React.string} </strong>
    //        <br />
    //      </div> : React.string("No Appearances")
    //  }
    // {switch (character##appearedIn) {
    //  | Some(appearedIn) =>
    //    <div>
    //        <strong> {"Has Appeared In: " |> React.string} </strong>
    //        <br />
    //      </div>
    //  | None => <div> React.string("No Appearances")</div>
    //  }}
    //  {character##appearedIn
    //  ->Belt.Option.map(season => season)
    //  ->Belt.Option.getWithDefault(React.null)
    //  }
    // {switch (character##appearedIn) {
    //  | Some(appearedIn) =>{
    //    Js.log(appearedIn);
    //    let seasons = Belt.Array.map(appearedIn, season => season);
    //    Js.log2("SEASONS", seasons);
    //    <div>
    //       <strong> {"Appeared In Should be here: " |> React.string} </strong> <br /> </div>}
    //      //  {
    //      //    appearedIn
    //      //     |> Js.Array.map((season) => <> season##name->React.string <br /> </>)
    //      //     |> React.array
    //      //   )}
    //  | None => React.null
    //  }}
    //  {renderListItem("Character appeared in", character##appearedIn)}
  </>;
};