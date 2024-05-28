import React from 'react';
import axios from "axios";

const BASE_URL: string = "https://vm.nathoro.ru/timetable/";

export const getTimetable = async (data: FormData) => {
    var room = "";
    if (data.get('room') !== null) {
        const roomValue = data.get('room');
        if (roomValue !== null) {
            room = roomValue.toString();
        }
    }
    return axios.get(BASE_URL + "by-room/" + encodeURIComponent(room));
}