<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormSearchStudent
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
        Me.srch_roll = New System.Windows.Forms.TextBox()
        Me.search = New System.Windows.Forms.Button()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.srch_name = New System.Windows.Forms.TextBox()
        Me.srch_dept = New System.Windows.Forms.TextBox()
        Me.srch_dcode = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(36, 64)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(171, 24)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Enter Roll Number:"
        '
        'srch_roll
        '
        Me.srch_roll.Location = New System.Drawing.Point(327, 67)
        Me.srch_roll.Name = "srch_roll"
        Me.srch_roll.Size = New System.Drawing.Size(186, 20)
        Me.srch_roll.TabIndex = 1
        '
        'search
        '
        Me.search.Location = New System.Drawing.Point(583, 64)
        Me.search.Name = "search"
        Me.search.Size = New System.Drawing.Size(92, 23)
        Me.search.TabIndex = 2
        Me.search.Text = "Search"
        Me.search.UseVisualStyleBackColor = True
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(81, 149)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(66, 24)
        Me.Label2.TabIndex = 3
        Me.Label2.Text = "Name:"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.Location = New System.Drawing.Point(81, 202)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(112, 24)
        Me.Label3.TabIndex = 4
        Me.Label3.Text = "Department:"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.Location = New System.Drawing.Point(81, 258)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(163, 24)
        Me.Label4.TabIndex = 5
        Me.Label4.Text = "Department Code:"
        '
        'srch_name
        '
        Me.srch_name.Location = New System.Drawing.Point(327, 152)
        Me.srch_name.Name = "srch_name"
        Me.srch_name.ReadOnly = True
        Me.srch_name.Size = New System.Drawing.Size(258, 20)
        Me.srch_name.TabIndex = 6
        '
        'srch_dept
        '
        Me.srch_dept.Location = New System.Drawing.Point(327, 202)
        Me.srch_dept.Name = "srch_dept"
        Me.srch_dept.ReadOnly = True
        Me.srch_dept.Size = New System.Drawing.Size(258, 20)
        Me.srch_dept.TabIndex = 7
        '
        'srch_dcode
        '
        Me.srch_dcode.Location = New System.Drawing.Point(327, 258)
        Me.srch_dcode.Name = "srch_dcode"
        Me.srch_dcode.ReadOnly = True
        Me.srch_dcode.Size = New System.Drawing.Size(258, 20)
        Me.srch_dcode.TabIndex = 8
        '
        'FormSearchStudent
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.srch_dcode)
        Me.Controls.Add(Me.srch_dept)
        Me.Controls.Add(Me.srch_name)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.search)
        Me.Controls.Add(Me.srch_roll)
        Me.Controls.Add(Me.Label1)
        Me.Name = "FormSearchStudent"
        Me.Text = "FormSearchStudent"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents srch_roll As TextBox
    Friend WithEvents search As Button
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents srch_name As TextBox
    Friend WithEvents srch_dept As TextBox
    Friend WithEvents srch_dcode As TextBox
End Class
