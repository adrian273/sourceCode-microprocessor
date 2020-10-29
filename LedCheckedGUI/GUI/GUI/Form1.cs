using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GUI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            serialPort1.Open();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
           
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                serialPort1.Write("1");
                label1.Text = "ON";
            }
            else
            {
                serialPort1.Write("0");
                label1.Text = "OFF";
            }
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked)
            {
                serialPort1.Write("2");
                label4.Text = "ON";
            }
            else
            {
                serialPort1.Write("3");
                label4.Text = "OFF";
            }

        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
         {
             if (checkBox3.Checked)
             {
                 serialPort1.Write("4");
                 label2.Text = "ON";
             }
             else
             {
                serialPort1.Write("5");
                label2.Text = "OFF";
             }
         }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox4.Checked)
            {
                serialPort1.Write("6");
                label3.Text = "ON";
            }
            else
            {
                serialPort1.Write("7");
                label3.Text = "OFF";
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
