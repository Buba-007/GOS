import React from 'react';
import { Navbar, Container, Nav } from 'react-bootstrap';
import { Link } from 'react-router-dom';

const Navabar = () => {
    return (
        <Navbar bg="primary" data-bs-theme="dark">
            <Container>
                <Navbar.Brand href="#">Экзамен</Navbar.Brand>
                <Nav className="me-auto">
                    <Nav.Link as={Link} to="/">Главная</Nav.Link>
                    <Nav.Link as={Link} to='/card'>Карточки</Nav.Link>
                    <Nav.Link as={Link} to='/table'>Таблица</Nav.Link>
                </Nav>
            </Container>
        </Navbar>
    )
};

export default Navabar;