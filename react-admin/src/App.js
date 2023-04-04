import { ColorModeContext, useMode } from './theme';
import { CssBaseline, ThemeProvider } from "@mui/material";
import { Routes, Route } from "react-router-dom";
import Topbar from "./scenes/global/Topbar";
import Sidebar from "./scenes/global/Sidebar";
import Dashboard from ".scenes/global/dashboard";
import Team from ".scenes/global/team";
import Invoices from ".scenes/global/invoices";
import Contacts from ".scenes/global/contacts";
import Bar from ".scenes/global/bar";
import Form from ".scenes/global/form";
import Line from ".scenes/global/line";
import Pie from ".scenes/global/pie";
import FAQ from ".scenes/global/faq";
import Geography from ".scenes/global/geography";

function App() {
  const [theme, colorMode] = useMode();

  return (
    <ColorModeContext.Provider value={colorMode}>
      <ThemeProvider theme={theme}>
        <CssBaseline />
        <div className="app">
          <main className="content">
            <Topbar />
            <Routes>
              <Route path="/" element={<Dashboard />} />
              <Route path="/team" element={<Dashboard />} />
              <Route path="/" element={<Dashboard />} />
              <Route path="/" element={<Dashboard />} />
              <Route path="/" element={<Dashboard />} />
              <Route path="/" element={<Dashboard />} />
              <Route path="/" element={<Dashboard />} />
              <Route path="/" element={<Dashboard />} />
              <Route path="/" element={<Dashboard />} />
            </Routes>
          </main>
        </div>
      </ThemeProvider>
    </ColorModeContext.Provider>
    );
}

export default App;
