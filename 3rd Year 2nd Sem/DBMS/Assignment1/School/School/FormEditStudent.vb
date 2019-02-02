Imports School.StudentList
Public Class FormEditStudent
    Dim index As Integer
    Private Sub search_edit_Click(sender As Object, e As EventArgs) Handles search_edit.Click
        ' First check if roll number exists
        If (edit_roll.Text = "") Then
            MessageBox.Show("Enter a roll to search")
            Return
        End If
        Dim flag As Integer
        flag = 0
        For i As Integer = 0 To stList.Count() - 1
            If (stList(i).getRoll() = edit_roll.Text) Then
                flag = 1
                ' Set texts
                edit_name.Text = stList(i).getName()
                edit_dept.Text = stList(i).getDept()
                edit_dcode.Text = stList(i).getDcode()
                index = i
                edit_save.Enabled = True
            End If
        Next

        If (flag = 0) Then
            MessageBox.Show("Invalid roll number")
        End If
    End Sub

    Private Sub edit_cancel_Click(sender As Object, e As EventArgs) Handles edit_cancel.Click
        Me.Close()
    End Sub

    Private Sub edit_save_Click(sender As Object, e As EventArgs) Handles edit_save.Click
        If (edit_roll.Text = "" Or edit_name.Text = "" Or edit_dept.Text = "") Then
            MessageBox.Show("Missing details")
            Return
        End If
        stList(index) = New Student(edit_roll.Text, edit_name.Text, edit_dept.Text, edit_dcode.Text)
        Me.Close()
    End Sub

    Private Sub edit_dept_SelectedIndexChanged(sender As Object, e As EventArgs) Handles edit_dept.SelectedIndexChanged
        ' Set dept code
        edit_dcode.Text = deptCode(edit_dept.SelectedIndex)
    End Sub

    Private Sub FormEditStudent_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ' Populate combo box
        For stepper = 0 To (depts.Count - 1)
            edit_dept.Items.Add(depts(stepper))
        Next

    End Sub
End Class