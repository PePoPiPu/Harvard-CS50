import { ColorModeContext, useMode } from './theme';
impor { CssBaseline, ThemeProvider } from "@mui/material";

function App() {
  const [theme, colorMode] = useMode();

  return (
    <ColorModeContext.Provide value={colorMode}>
      <ThemeProvider theme={theme}>
        <CssBaseline />
        <div className="app">
          <main className="content"></main>
          </div>
      </ThemeProvider>
    </ColorModeContext.Provide>
    );
}

export default App;
