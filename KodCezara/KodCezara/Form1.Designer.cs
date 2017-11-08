namespace KodCezara
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.kodujtekst = new System.Windows.Forms.Button();
            this.kodujplik = new System.Windows.Forms.Button();
            this.tekst = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.sciezkadostepu = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.kodujtekst.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.kodujtekst.Location = new System.Drawing.Point(671, 91);
            this.kodujtekst.Name = "button1";
            this.kodujtekst.Size = new System.Drawing.Size(149, 47);
            this.kodujtekst.TabIndex = 0;
            this.kodujtekst.Text = "Zakoduj tekst";
            this.kodujtekst.UseVisualStyleBackColor = true;
            this.kodujtekst.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.kodujplik.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.kodujplik.Location = new System.Drawing.Point(671, 203);
            this.kodujplik.Name = "button2";
            this.kodujplik.Size = new System.Drawing.Size(149, 47);
            this.kodujplik.TabIndex = 1;
            this.kodujplik.Text = "Zakoduj plik";
            this.kodujplik.UseVisualStyleBackColor = true;
            this.kodujplik.Click += new System.EventHandler(this.button2_Click);
            // 
            // textBox1
            // 
            this.tekst.Location = new System.Drawing.Point(43, 91);
            this.tekst.Multiline = true;
            this.tekst.Name = "textBox1";
            this.tekst.Size = new System.Drawing.Size(594, 47);
            this.tekst.TabIndex = 2;
            this.tekst.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.Location = new System.Drawing.Point(40, 55);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(313, 20);
            this.label1.TabIndex = 3;
            this.label1.Text = "Kodowanie tekstu z pola tekstowego";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // textBox2
            // 
            this.sciezkadostepu.Location = new System.Drawing.Point(155, 203);
            this.sciezkadostepu.Name = "textBox2";
            this.sciezkadostepu.Size = new System.Drawing.Size(482, 22);
            this.sciezkadostepu.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label2.Location = new System.Drawing.Point(40, 161);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(160, 20);
            this.label2.TabIndex = 5;
            this.label2.Text = "Kodowanie z pliku";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(38, 203);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(116, 17);
            this.label3.TabIndex = 6;
            this.label3.Text = "Ścieżka dostępu:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkKhaki;
            this.ClientSize = new System.Drawing.Size(901, 345);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.sciezkadostepu);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tekst);
            this.Controls.Add(this.kodujplik);
            this.Controls.Add(this.kodujtekst);
            this.Name = "Form1";
            this.Text = "KodCezara";
            this.UseWaitCursor = true;
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button kodujtekst;
        private System.Windows.Forms.Button kodujplik;
        private System.Windows.Forms.TextBox tekst;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox sciezkadostepu;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}

