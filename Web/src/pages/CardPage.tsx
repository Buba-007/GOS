import React, {useEffect} from "react";
import { Container, Card, Button } from "react-bootstrap";
import '../static/css/cardpage.css';

const CardPage = () => {
    useEffect(() => {
        document.title = "Карточки";
    }, []);
    
    return (<>
        <Container className="card-container">
            <Card className="card-item" style={{ width: '18rem' }}>
                <Card.Img variant="top" src="https://is.ulstu.ru/Images/yng.jpg" />
                <Card.Body>
                    <Card.Title>Card Title</Card.Title>
                    <Card.Text>
                        Some quick example text to build on the card title and make up the
                        bulk of the card's content.
                    </Card.Text>
                    <Button variant="primary">Go somewhere</Button>
                </Card.Body>
            </Card>
            <Card className="card-item" style={{ width: '18rem' }}>
                <Card.Img variant="top" src="https://is.ulstu.ru/Images/yng.jpg" />
                <Card.Body>
                    <Card.Title>Card Title</Card.Title>
                    <Card.Text>
                        Some quick example text to build on the card title and make up the
                        bulk of the card's content.
                    </Card.Text>
                    <Button variant="primary">Go somewhere</Button>
                </Card.Body>
            </Card>
            <Card className="card-item" style={{ width: '18rem' }}>
                <Card.Img variant="top" src="https://is.ulstu.ru/Images/yng.jpg" />
                <Card.Body>
                    <Card.Title>Card Title</Card.Title>
                    <Card.Text>
                        Some quick example text to build on the card title and make up the
                        bulk of the card's content.
                    </Card.Text>
                    <Button variant="primary">Go somewhere</Button>
                </Card.Body>
            </Card>
            <Card className="card-item" style={{ width: '18rem' }}>
                <Card.Img variant="top" src="https://is.ulstu.ru/Images/yng.jpg" />
                <Card.Body>
                    <Card.Title>Card Title</Card.Title>
                    <Card.Text>
                        Some quick example text to build on the card title and make up the
                        bulk of the card's content.
                    </Card.Text>
                    <Button variant="primary">Go somewhere</Button>
                </Card.Body>
            </Card>
            <Card className="card-item" style={{ width: '18rem' }}>
                <Card.Img variant="top" src="https://is.ulstu.ru/Images/yng.jpg" />
                <Card.Body>
                    <Card.Title>Card Title</Card.Title>
                    <Card.Text>
                        Some quick example text to build on the card title and make up the
                        bulk of the card's content.
                    </Card.Text>
                    <Button variant="primary">Go somewhere</Button>
                </Card.Body>
            </Card>
        </Container>
    </>)
};

export default CardPage;