<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormDelStudent
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
        Me.search_del = New System.Windows.Forms.Button()
        Me.del_roll = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.del_dcode = New System.Windows.Forms.TextBox()
        Me.del_dept = New System.Windows.Forms.TextBox()
        Me.del_name = New System.Windows.Forms.TextBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.del_save = New System.Windows.Forms.Button()
        Me.del_cancel = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'search_del
        '
        Me.search_del.Location = New System.Drawing.Point(487, 89)
        Me.search_del.Name = "search_del"
        Me.search_del.Size = New System.Drawing.Size(92, 23)
        Me.search_del.TabIndex = 14
        Me.search_del.Text = "Search"
        Me.search_del.UseVisualStyleBackColor = True
        '
        'del_roll
        '
        Me.del_roll.Location = New System.Drawing.Point(251, 91)
        Me.del_roll.Name = "del_roll"
        Me.del_roll.Size = New System.Drawing.Size(186, 20)
        Me.del_roll.TabIndex = 13
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(47, 89)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(171, 24)
        Me.Label1.TabIndex = 12
        Me.Label1.Text = "Enter Roll Number:"
        '
        'del_dcode
        '
        Me.del_dcode.Location = New System.Drawing.Point(303, 266)
        Me.del_dcode.Name = "del_dcode"
        Me.del_dcode.ReadOnly = True
        Me.del_dcode.Size = New System.Drawing.Size(258, 20)
        Me.del_dcode.TabIndex = 20
        '
        'del_dept
        '
        Me.del_dept.Location = New System.Drawing.Point(303, 210)
        Me.del_dept.Name = "del_dept"
        Me.del_dept.ReadOnly = True
        Me.del_dept.Size = New System.Drawing.Size(258, 20)
        Me.del_dept.TabIndex = 19
        '
        'del_name
        '
        Me.del_name.Location = New System.Drawing.Point(303, 160)
        Me.del_name.Name = "del_name"
        Me.del_name.ReadOnly = True
        Me.del_name.Size = New System.Drawing.Size(258, 20)
        Me.del_name.TabIndex = 18
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.Location = New System.Drawing.Point(57, 266)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(163, 24)
        Me.Label4.TabIndex = 17
        Me.Label4.Text = "Department Code:"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.Location = New System.Drawing.Point(57, 210)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(112, 24)
        Me.Label3.TabIndex = 16
        Me.Label3.Text = "Department:"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(57, 157)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(66, 24)
        Me.Label2.TabIndex = 15
        Me.Label2.Text = "Name:"
        '
        'del_save
        '
        Me.del_save.Enabled = False
        Me.del_save.Location = New System.Drawing.Point(342, 338)
        Me.del_save.Name = "del_save"
        Me.del_save.Size = New System.Drawing.Size(130, 23)
        Me.del_save.TabIndex = 22
        Me.del_save.Text = "Delete"
        Me.del_save.UseVisualStyleBackColor = True
        '
        'del_cancel
        '
        Me.del_cancel.Location = New System.Drawing.Point(160, 338)
        Me.del_cancel.Name = "del_cancel"
        Me.del_cancel.Size = New System.Drawing.Size(130, 23)
        Me.del_cancel.TabIndex = 21
        Me.del_cancel.Text = "Cancel"
        Me.del_cancel.UseVisualStyleBackColor = True
        '
        'FormDelStudent
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(656, 450)
        Me.Controls.Add(Me.del_save)
        Me.Controls.Add(Me.del_cancel)
        Me.Controls.Add(Me.del_dcode)
        Me.Controls.Add(Me.del_dept)
        Me.Controls.Add(Me.del_name)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.search_del)
        Me.Controls.Add(Me.del_roll)
        Me.Controls.Add(Me.Label1)
        Me.Name = "FormDelStudent"
        Me.Text = "FormDelStudent"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents search_del As Button
    Friend WithEvents del_roll As TextBox
    Friend WithEvents Label1 As Label
    Friend WithEvents del_dcode As TextBox
    Friend WithEvents del_dept As TextBox
    Friend WithEvents del_name As TextBox
    Friend WithEvents Label4 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents del_save As Button
    Friend WithEvents del_cancel As Button
End Class
