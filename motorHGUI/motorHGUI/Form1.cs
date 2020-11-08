using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace motorHGUI
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
            //serialPort1.Write("600");
        }

        
        private void button1_Click(object sender, EventArgs e)
        {
            if (pos2.Text != "0")
            {
                pos2.Text = "0";
            }
            String data = pos1.Text;
            pictureBox1.Image = Resources.motorImageLeft;
            serialPort1.Write(data);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (pos1.Text != "0")
            {
                pos1.Text = "0";
            }
            String data = pos2.Text;
            pictureBox1.Image = Resources.motorImageRight;
            serialPort1.Write("-"+data);
        }
    }
}
