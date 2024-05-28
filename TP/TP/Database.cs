using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TP
{
    public class Database : DbContext
    {
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (optionsBuilder.IsConfigured == false)
            {
                optionsBuilder.UseSqlite("Data Source=mydatabase.db");
            }
            base.OnConfiguring(optionsBuilder);
        }
        public virtual DbSet<Patient> Patients { set; get; }
        public virtual DbSet<Doctor> Doctors { set; get; }
    }
}
