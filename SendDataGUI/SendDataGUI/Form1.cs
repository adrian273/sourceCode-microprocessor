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
        String[] n;
        public Form1()
        {
            InitializeComponent();
            serialPort1.Open();
            serialPort1.DataReceived += serialPort1_DataReceived;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            string POT = serialPort1.ReadLine();
            
            this.BeginInvoke(new LineReceivedEvent(LineReceived), POT);
        }

        string[] words;

        private delegate void LineReceivedEvent(string inData);

        public void LineReceived(string inData)
        {
            label1.Text = inData;
            if (label1.Text == "3")
            {
                pictureBox3.Image = Resources.on;
            }
            if (label1.Text == "4")
            {
                pictureBox4.Image = Resources.on;
            }

            Nn(inData);
            inData = "";
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        public void Nn(string d)
        {
            System.Console.WriteLine("es un numero" + d);
            label2.Text = d;
            if (label2.Text == "1")
            {
                img1.Image = Resources.on;
            }
            
            if (label2.Text == "2")
            {
                img2.Image = Resources.on;
            }

            if (label2.Text == "3")
            {
                pictureBox3.Image = Resources.on;
            }

            if (label2.Text == "4")
            {
                pictureBox4.Image = Resources.on;
            }
            d = "";
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {

        }
    }
}
