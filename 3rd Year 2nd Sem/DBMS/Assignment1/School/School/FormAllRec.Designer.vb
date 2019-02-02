<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormAllRec
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.prev_btn = New System.Windows.Forms.Button()
        Me.next_btn = New System.Windows.Forms.Button()
        Me.records = New System.Windows.Forms.DataGridView()
        Me.roll = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.name_rec = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.dept = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.dcode = New System.Windows.Forms.DataGridViewTextBoxColumn()
        CType(Me.records, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'prev_btn
        '
        Me.prev_btn.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.prev_btn.Location = New System.Drawing.Point(263, 343)
        Me.prev_btn.Name = "prev_btn"
        Me.prev_btn.Size = New System.Drawing.Size(107, 35)
        Me.prev_btn.TabIndex = 1
        Me.prev_btn.Text = "< PREV"
        Me.prev_btn.UseVisualStyleBackColor = True
        '
        'next_btn
        '
        Me.next_btn.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.next_btn.Location = New System.Drawing.Point(451, 343)
        Me.next_btn.Name = "next_btn"
        Me.next_btn.Size = New System.Drawing.Size(107, 35)
        Me.next_btn.TabIndex = 2
        Me.next_btn.Text = "NEXT >"
        Me.next_btn.UseVisualStyleBackColor = True
        '
        'records
        '
        Me.records.AllowUserToAddRows = False
        Me.records.AllowUserToDeleteRows = False
        Me.records.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
        Me.records.Columns.AddRange(New System.Windows.Forms.DataGridViewColumn() {Me.roll, Me.name_rec, Me.dept, Me.dcode})
        Me.records.Location = New System.Drawing.Point(122, 50)
        Me.records.Name = "records"
        Me.records.ReadOnly = True
        Me.records.Size = New System.Drawing.Size(493, 150)
        Me.records.TabIndex = 3
        '
        'roll
        '
        Me.roll.Frozen = True
        Me.roll.HeaderText = "Roll No."
        Me.roll.Name = "roll"
        Me.roll.ReadOnly = True
        Me.roll.Width = 50
        '
        'name_rec
        '
        Me.name_rec.Frozen = True
        Me.name_rec.HeaderText = "Name"
        Me.name_rec.Name = "name_rec"
        Me.name_rec.ReadOnly = True
        Me.name_rec.Width = 150
        '
        'dept
        '
        Me.dept.Frozen = True
        Me.dept.HeaderText = "Department"
        Me.dept.Name = "dept"
        Me.dept.ReadOnly = True
        Me.dept.Width = 150
        '
        'dcode
        '
        Me.dcode.Frozen = True
        Me.dcode.HeaderText = "Department Code"
        Me.dcode.Name = "dcode"
        Me.dcode.ReadOnly = True
        '
        'FormAllRec
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.records)
        Me.Controls.Add(Me.next_btn)
        Me.Controls.Add(Me.prev_btn)
        Me.Name = "FormAllRec"
        Me.Text = "FormAllRec"
        CType(Me.records, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents prev_btn As Button
    Friend WithEvents next_btn As Button
    Friend WithEvents records As DataGridView
    Friend WithEvents roll As DataGridViewTextBoxColumn
    Friend WithEvents name_rec As DataGridViewTextBoxColumn
    Friend WithEvents dept As DataGridViewTextBoxColumn
    Friend WithEvents dcode As DataGridViewTextBoxColumn
End Class
