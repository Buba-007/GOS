import React, { FormEvent, useEffect, useState } from 'react';
import { Form, Table, Button, Container } from 'react-bootstrap';
import Swal from 'sweetalert2';

import { getTimetable } from '../actions/actions';
import { error } from 'console';

interface Lesson {
    group: {
        name: string;
    };
    room: {
        name: string;
    };
    subject: {
        teacher: {
            fullName: string;
        };
        name: string;
        type: string;
    };
}

interface Day {
    lessons: Lesson[];
}

interface TableInfo {
    days: Day[];
    isOdd: boolean;
}


const TablePage = () => {
    useEffect(() => {
        document.title = "Таблицы";
    }, []);
    
    const [formData, setFormData] = useState(new FormData());
    const [tableData, setTableData] = useState<TableInfo[]>([]);

    const handleSubmit = (e: FormEvent) => {
        e.preventDefault();

        getTimetable(formData).then(result => {
            setTableData(result.data);
        }).catch(error => {
            Swal.fire({
                title: 'Ошибка',
                text: error.message,
                icon: 'error',
                confirmButtonText: 'OK'
            });
        });
    };

    return (<>
        <Container>
            <Form onSubmit={e => handleSubmit(e)}>
                <Form.Group className="mb-3" controlId="formBasicEmail">
                    <Form.Label>Введите аудиторию</Form.Label>
                    <Form.Control
                        type="text"
                        placeholder="Введите аудиторию"
                        onChange={e => {
                            const newFormData = new FormData();
                            newFormData.append('room', e.target.value);
                            setFormData(newFormData);
                        }}
                    />
                </Form.Group>
                <Button variant="primary" type="submit">
                    Построить
                </Button>
            </Form>
            <Button variant="danger" onClick={() => setTableData([])}>
                Очистить
            </Button>

            {tableData.map((tableInnf, index) => (<>
                <h4 key={index}>
                    {tableInnf.isOdd === true ? ("Чётная неделя") : ("Нечётная неделя")}
                </h4>
                <Table>
                    <thead>
                        <tr>
                            <th style={{ width: "10vw" }}>1</th>
                            <th style={{ width: "10vw" }}>2</th>
                            <th style={{ width: "10vw" }}>3</th>
                            <th style={{ width: "10vw" }}>4</th>
                            <th style={{ width: "10vw" }}>5</th>
                            <th style={{ width: "10vw" }}>6</th>
                            <th style={{ width: "10vw" }}>7</th>
                            <th style={{ width: "10vw" }}>8</th>
                        </tr>
                    </thead>
                    {tableInnf.days.map((day, index) => (<>
                        <tr>
                            {day.lessons.map((lesson, index) => (<>
                                {lesson !== null ? (
                                    <td style={{ backgroundColor: "lightcoral" }}>
                                        {"Группа: " + lesson.group.name + " Предмет: " + lesson.subject.name}
                                    </td>
                                ) : (
                                    <td style={{ backgroundColor: "lightgreen" }}>-</td>
                                )}
                            </>))}
                        </tr>
                    </>))}
                </Table>
            </>)
            )}
        </Container>
    </>)
};

export default TablePage;