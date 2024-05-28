import React, {useEffect} from 'react';
import { Container, Col, Row, Form, Button } from 'react-bootstrap';
import '../static/css/home.css';

const Home = () => {
    useEffect(() => {
        document.title = "Главная";
    }, []);

    return (<>
        <Container className='home-container'>
            <Row>
                <Col>
                    <Form className='form-login'>
                        <Form.Group className="mb-3" controlId="formBasicEmail">
                            <Form.Label>Логин</Form.Label>
                            <Form.Control type="username" placeholder="Enter email" />
                        </Form.Group>
                        <Form.Group className="mb-3" controlId="formBasicPassword">
                            <Form.Label>Пароль</Form.Label>
                            <Form.Control type="password" placeholder="Password" />
                        </Form.Group>
                        <Button variant="primary">
                            Войти
                        </Button>
                    </Form>
                </Col>
                <Col xs={9} className='home-info'>
                    <h3>Надежда Глебовна (тётя)</h3>
                    <img src='https://is.ulstu.ru/Images/yng.jpg' alt='Надежда Глебовна (тётя)'/>
                    <p>
                        Кафедра основана в 1997 году на факультете Информационных систем и технологий
                        Адрес кафедры: 432027, г. Ульяновск, ул. Северный Венец, 32, 3 учебный корпус, ауд.422
                        Телефон кафедры: (8422) 77-80-79
                        Адрес электронной почты: jng@ulstu.ru
                    </p>
                    <p>
                        Заведующий кафедрой - д.т.н., профессор Ярушкина Надежда Глебовна
                        Кафедра осуществляет подготовку по следующим направлениям:
                        направление 09.03.03 «Прикладная информатика» (профиль «Прикладная информатика в экономике»). Квалификация - бакалавр;
                        направление 09.03.04 «Программная инженерия». Квалификация – бакалавр.
                        направление 09.04.04 «Программная инженерия». Квалификация – магистр.
                        направление 09.04.03 «Прикладная информатика». Квалификация – магистр.
                    </p>
                    <p>
                        При кафедре работает аспирантура по специальностям:
                        05.13.12 - Системы автоматизации проектирования,
                        05.13.18 - Математическое моделирование, численные методы и комплексы программ,
                        08.00.05 - Экономика и управление народным хозяйством.
                    </p>
                </Col>
            </Row>
        </Container>
    </>)
};

export default Home;