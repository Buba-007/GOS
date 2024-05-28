using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TP
{
    public class Doctor
    {
        public int ID {  get; set; }
        public string Name { get; set; }
        public string Quality { get; set; }
        [ForeignKey("DoctorID")]
        public virtual List<Patient> Patients { get; set; }
    }
}
