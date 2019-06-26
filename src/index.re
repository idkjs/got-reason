open Utils;
let serverUri = "http://localhost:4000";
let instance =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.createHttpLink(~uri=serverUri, ()),
    ~cache=ApolloInMemoryCache.createInMemoryCache(),
    (),
  );
  
ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=instance> <App /> </ReasonApollo.Provider>,
  "index",
);

if (hot) {
  accept();
};