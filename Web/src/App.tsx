import React from 'react';
import 'bootstrap/dist/css/bootstrap.min.css';
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import './static/css/app.css';

import Navabar from './layouts/navbar';
import Footer from './layouts/footer';
import Home from './pages/home';
import CardPage from './pages/CardPage';
import TablePage from './pages/TablePage';

const App = () => {

  return (<>
    <BrowserRouter>
      <Navabar />
      <div className='main-container'>
        <Routes>
          <Route path='/' element={
            <div className='content-container'>
              <Home />
            </div>
            } />
          <Route path='/card' element={
            <div className='content-container'>
              <CardPage/>
            </div>
          } />
          <Route path='/table' element={
            <div className='content-container'>
              <TablePage/>
            </div>
          } />
        </Routes>

        <Footer />
      </div>

    </BrowserRouter>
  </>);
}

export default App;
