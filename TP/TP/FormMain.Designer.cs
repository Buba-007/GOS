namespace TP
{
    partial class FormMain
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
            buttonAdd = new Button();
            groupBoxAdd = new GroupBox();
            label3 = new Label();
            label2 = new Label();
            label1 = new Label();
            numRoomNumb = new NumericUpDown();
            numAge = new NumericUpDown();
            textBoxName = new TextBox();
            groupBoxAge = new GroupBox();
            numFilterAge = new NumericUpDown();
            buttonRemoveFilter = new Button();
            buttonAgeFilter = new Button();
            groupBoxRoom = new GroupBox();
            labelGroup = new Label();
            buttonRemoveGroup = new Button();
            buttonGroup = new Button();
            label4 = new Label();
            viewPatients = new DataGridView();
            groupBoxAdd.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)numRoomNumb).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numAge).BeginInit();
            groupBoxAge.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)numFilterAge).BeginInit();
            groupBoxRoom.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)viewPatients).BeginInit();
            SuspendLayout();
            // 
            // buttonAdd
            // 
            buttonAdd.Location = new Point(250, 177);
            buttonAdd.Name = "buttonAdd";
            buttonAdd.Size = new Size(105, 35);
            buttonAdd.TabIndex = 0;
            buttonAdd.Text = "Добавить";
            buttonAdd.UseVisualStyleBackColor = true;
            buttonAdd.Click += buttonAdd_Click;
            // 
            // groupBoxAdd
            // 
            groupBoxAdd.Controls.Add(label3);
            groupBoxAdd.Controls.Add(label2);
            groupBoxAdd.Controls.Add(label1);
            groupBoxAdd.Controls.Add(numRoomNumb);
            groupBoxAdd.Controls.Add(numAge);
            groupBoxAdd.Controls.Add(buttonAdd);
            groupBoxAdd.Controls.Add(textBoxName);
            groupBoxAdd.Location = new Point(12, 12);
            groupBoxAdd.Name = "groupBoxAdd";
            groupBoxAdd.Size = new Size(374, 229);
            groupBoxAdd.TabIndex = 2;
            groupBoxAdd.TabStop = false;
            groupBoxAdd.Text = "Добавление пациента";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(18, 130);
            label3.Name = "label3";
            label3.Size = new Size(114, 20);
            label3.TabIndex = 5;
            label3.Text = "Номер палаты:";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(18, 89);
            label2.Name = "label2";
            label2.Size = new Size(67, 20);
            label2.TabIndex = 4;
            label2.Text = "Возраст:";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(18, 48);
            label1.Name = "label1";
            label1.Size = new Size(42, 20);
            label1.TabIndex = 3;
            label1.Text = "Имя:";
            // 
            // numRoomNumb
            // 
            numRoomNumb.Location = new Point(205, 130);
            numRoomNumb.Name = "numRoomNumb";
            numRoomNumb.Size = new Size(150, 27);
            numRoomNumb.TabIndex = 2;
            // 
            // numAge
            // 
            numAge.Location = new Point(205, 87);
            numAge.Name = "numAge";
            numAge.Size = new Size(150, 27);
            numAge.TabIndex = 1;
            // 
            // textBoxName
            // 
            textBoxName.Location = new Point(89, 45);
            textBoxName.Name = "textBoxName";
            textBoxName.Size = new Size(266, 27);
            textBoxName.TabIndex = 0;
            // 
            // groupBoxAge
            // 
            groupBoxAge.Controls.Add(numFilterAge);
            groupBoxAge.Controls.Add(buttonRemoveFilter);
            groupBoxAge.Controls.Add(buttonAgeFilter);
            groupBoxAge.Location = new Point(12, 247);
            groupBoxAge.Name = "groupBoxAge";
            groupBoxAge.Size = new Size(374, 85);
            groupBoxAge.TabIndex = 3;
            groupBoxAge.TabStop = false;
            groupBoxAge.Text = "Старше возраста";
            // 
            // numFilterAge
            // 
            numFilterAge.Location = new Point(18, 41);
            numFilterAge.Name = "numFilterAge";
            numFilterAge.Size = new Size(114, 27);
            numFilterAge.TabIndex = 2;
            // 
            // buttonRemoveFilter
            // 
            buttonRemoveFilter.Location = new Point(261, 39);
            buttonRemoveFilter.Name = "buttonRemoveFilter";
            buttonRemoveFilter.Size = new Size(94, 29);
            buttonRemoveFilter.TabIndex = 1;
            buttonRemoveFilter.Text = "Сброс";
            buttonRemoveFilter.UseVisualStyleBackColor = true;
            buttonRemoveFilter.Click += buttonRemoveFilter_Click;
            // 
            // buttonAgeFilter
            // 
            buttonAgeFilter.Location = new Point(152, 39);
            buttonAgeFilter.Name = "buttonAgeFilter";
            buttonAgeFilter.Size = new Size(94, 29);
            buttonAgeFilter.TabIndex = 0;
            buttonAgeFilter.Text = "Вывод";
            buttonAgeFilter.UseVisualStyleBackColor = true;
            buttonAgeFilter.Click += buttonAgeFilter_Click;
            // 
            // groupBoxRoom
            // 
            groupBoxRoom.Controls.Add(labelGroup);
            groupBoxRoom.Controls.Add(buttonRemoveGroup);
            groupBoxRoom.Controls.Add(buttonGroup);
            groupBoxRoom.Controls.Add(label4);
            groupBoxRoom.Location = new Point(12, 338);
            groupBoxRoom.Name = "groupBoxRoom";
            groupBoxRoom.Size = new Size(374, 111);
            groupBoxRoom.TabIndex = 4;
            groupBoxRoom.TabStop = false;
            groupBoxRoom.Text = "Группировка по палатам";
            // 
            // labelGroup
            // 
            labelGroup.AutoSize = true;
            labelGroup.Location = new Point(261, 32);
            labelGroup.Name = "labelGroup";
            labelGroup.Size = new Size(18, 20);
            labelGroup.TabIndex = 4;
            labelGroup.Text = "...";
            // 
            // buttonRemoveGroup
            // 
            buttonRemoveGroup.Location = new Point(261, 71);
            buttonRemoveGroup.Name = "buttonRemoveGroup";
            buttonRemoveGroup.Size = new Size(94, 29);
            buttonRemoveGroup.TabIndex = 3;
            buttonRemoveGroup.Text = "Сброс";
            buttonRemoveGroup.UseVisualStyleBackColor = true;
            buttonRemoveGroup.Click += buttonRemoveGroup_Click;
            // 
            // buttonGroup
            // 
            buttonGroup.Location = new Point(152, 71);
            buttonGroup.Name = "buttonGroup";
            buttonGroup.Size = new Size(94, 29);
            buttonGroup.TabIndex = 2;
            buttonGroup.Text = "Вывод";
            buttonGroup.UseVisualStyleBackColor = true;
            buttonGroup.Click += buttonGroup_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(6, 32);
            label4.Name = "label4";
            label4.Size = new Size(247, 20);
            label4.TabIndex = 0;
            label4.Text = "Больше всего пациентов в палате";
            // 
            // viewPatients
            // 
            viewPatients.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            viewPatients.Location = new Point(392, 23);
            viewPatients.Name = "viewPatients";
            viewPatients.RowHeadersWidth = 51;
            viewPatients.Size = new Size(669, 426);
            viewPatients.TabIndex = 5;
            // 
            // FormMain
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1073, 464);
            Controls.Add(viewPatients);
            Controls.Add(groupBoxRoom);
            Controls.Add(groupBoxAge);
            Controls.Add(groupBoxAdd);
            Name = "FormMain";
            Text = "Главная";
            FormClosed += FormMain_FormClosed;
            Load += FormMain_Load;
            groupBoxAdd.ResumeLayout(false);
            groupBoxAdd.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)numRoomNumb).EndInit();
            ((System.ComponentModel.ISupportInitialize)numAge).EndInit();
            groupBoxAge.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)numFilterAge).EndInit();
            groupBoxRoom.ResumeLayout(false);
            groupBoxRoom.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)viewPatients).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private Button buttonAdd;
        private GroupBox groupBoxAdd;
        private TextBox textBoxName;
        private NumericUpDown numRoomNumb;
        private NumericUpDown numAge;
        private Label label1;
        private Label label2;
        private Label label3;
        private GroupBox groupBoxAge;
        private NumericUpDown numFilterAge;
        private Button buttonRemoveFilter;
        private Button buttonAgeFilter;
        private GroupBox groupBoxRoom;
        private Label labelGroup;
        private Button buttonRemoveGroup;
        private Button buttonGroup;
        private Label label4;
        private DataGridView viewPatients;
    }
}