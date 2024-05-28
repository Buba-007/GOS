using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;

namespace TP
{
    public partial class FormMain : Form
    {
        List<Patient>? patients;
        public FormMain()
        {
            patients = new List<Patient>();
            InitializeComponent();
        }

        private void UpdateDataGrid(List<Patient> data)
        {
            viewPatients.DataSource = null;
            viewPatients.DataSource = data;
            viewPatients.Columns[0].Visible = false;
            viewPatients.Columns[1].AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            viewPatients.Columns[4].Visible = false;
            viewPatients.Columns[5].Visible = false;
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            string json = File.ReadAllText("patients.json");
            patients = JsonConvert.DeserializeObject<List<Patient>>(json);
            if (patients != null)
            {
                UpdateDataGrid(patients);
            }
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            if (textBoxName.Text != "")
            {
                Patient patient = new Patient();
                patient.ID = patients != null ? (patients.Any() ? patients.Last().ID + 1 : 0) : 0;
                patient.Name = textBoxName.Text;
                patient.Age = Convert.ToInt32(numAge.Value);
                patient.RoomNumb = Convert.ToInt32(numRoomNumb.Value);
                patient.DoctorId = 0;
                patients.Add(patient);

                UpdateDataGrid(patients);
            }
        }

        private void buttonAgeFilter_Click(object sender, EventArgs e)
        {
            var f_patients = from p in patients
                             where p.Age > Convert.ToInt32(numFilterAge.Value)
                             select p;
            UpdateDataGrid(f_patients.ToList());
            groupBoxAge.BackColor = Color.LightGreen;
        }

        private void buttonRemoveFilter_Click(object sender, EventArgs e)
        {
            UpdateDataGrid(patients);
            numFilterAge.Value = 0;
            groupBoxAge.BackColor = Color.Transparent;
        }

        private void buttonGroup_Click(object sender, EventArgs e)
        {
            var g_patients = patients
                .GroupBy(p => p.RoomNumb)
                .Select(g => new { RoomNumb = g.Key, Count = g.Count() })
                .OrderByDescending(r => r.Count);
            labelGroup.Text = "" + g_patients.First().RoomNumb;

            groupBoxRoom.BackColor = Color.LightGreen;
        }

        private void buttonRemoveGroup_Click(object sender, EventArgs e)
        {
            labelGroup.Text = "...";
            groupBoxRoom.BackColor = Color.Transparent;
        }

        private void FormMain_FormClosed(object sender, FormClosedEventArgs e)
        {
            var json = JsonConvert.SerializeObject(patients);
            File.WriteAllText("patients.json", json);
        }
    }
}
