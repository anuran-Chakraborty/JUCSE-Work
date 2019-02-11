<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
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
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.sum = New System.Windows.Forms.TextBox()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.first = New System.Windows.Forms.NumericUpDown()
        Me.second = New System.Windows.Forms.NumericUpDown()
        CType(Me.first, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.second, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label1.Location = New System.Drawing.Point(16, 22)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(154, 20)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Enter first number"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label2.Location = New System.Drawing.Point(16, 62)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(181, 20)
        Me.Label2.TabIndex = 3
        Me.Label2.Text = "Enter second number"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label3.Location = New System.Drawing.Point(16, 105)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(171, 20)
        Me.Label3.TabIndex = 4
        Me.Label3.Text = "Sum of the numbers"
        '
        'sum
        '
        Me.sum.Location = New System.Drawing.Point(234, 107)
        Me.sum.Name = "sum"
        Me.sum.ReadOnly = True
        Me.sum.Size = New System.Drawing.Size(100, 20)
        Me.sum.TabIndex = 6
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(122, 168)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(94, 23)
        Me.Button1.TabIndex = 8
        Me.Button1.Text = "Calculate sum"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'first
        '
        Me.first.Location = New System.Drawing.Point(234, 22)
        Me.first.Maximum = New Decimal(New Integer() {32767, 0, 0, 0})
        Me.first.Minimum = New Decimal(New Integer() {32768, 0, 0, -2147483648})
        Me.first.Name = "first"
        Me.first.Size = New System.Drawing.Size(100, 20)
        Me.first.TabIndex = 9
        '
        'second
        '
        Me.second.Location = New System.Drawing.Point(234, 65)
        Me.second.Maximum = New Decimal(New Integer() {32767, 0, 0, 0})
        Me.second.Minimum = New Decimal(New Integer() {32768, 0, 0, -2147483648})
        Me.second.Name = "second"
        Me.second.Size = New System.Drawing.Size(100, 20)
        Me.second.TabIndex = 10
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(366, 239)
        Me.Controls.Add(Me.second)
        Me.Controls.Add(Me.first)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.sum)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        CType(Me.first, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.second, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents sum As TextBox
    Friend WithEvents Button1 As Button
    Friend WithEvents first As NumericUpDown
    Friend WithEvents second As NumericUpDown
End Class
