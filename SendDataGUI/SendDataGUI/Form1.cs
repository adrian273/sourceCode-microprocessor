using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using SendDataGUI.Properties;

namespace SendDataGUI
{
    public partial class Form1 : Form
    {
        
        public Form1()
        {
            InitializeComponent();
            serialPort1.Open();
            serialPort1.DataReceived += serialPort1_DataReceived;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            progressBar1.Value = 0;
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            string POT = serialPort1.ReadLine();
            
            this.BeginInvoke(new LineReceivedEvent(LineReceived), POT);
        }

           private delegate void LineReceivedEvent(string inData);

        public void LineReceived(string inData)
        {
            label1.Text = inData;

            //int n = int.Parse(inData.ToString());
            int n;
            
            if (Int32.TryParse(inData.ToString(), out n))
            {
                progressBar1.Value = n;
                label2.Text = "Sin Energia";
                if (n == 0)
                {
                    pictureBox1.Image = Resources.bulb_0;
                    label2.Text = "Sin Energia";
                } else if (n > 0 && n <= 50)
                {
                    label2.Text = "Energia Media";
                    pictureBox1.Image = Resources.bulb_1;
                } else if (n > 50 && n <= 100) {
                    label2.Text = "Energia Alta";
                    pictureBox1.Image = Resources.bulb_3;
                }
            }
            inData = "";
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        public void Nn(string d)
        {
            
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }
    }
}
