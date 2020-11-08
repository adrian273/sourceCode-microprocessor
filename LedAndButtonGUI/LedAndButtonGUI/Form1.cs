using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LedAndButtonGUI
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

        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            string POT = serialPort1.ReadLine();

            this.BeginInvoke(new LineReceivedEvent(LineReceived), POT);
        }

        private delegate void LineReceivedEvent(string inData);

        public void LineReceived(string inData)
        {
           
            int n;
            label1.Text = inData;

            if (Int32.TryParse(inData.ToString(), out n))
            {
               if (n == 1)
                {
                    pictureBox1.Image = Resources.on;
                }
               else if (n == 0)
                {
                    pictureBox1.Image = Resources.off;
                }
            }
            inData = "";
        }
    }
}
